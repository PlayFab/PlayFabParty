<#
.SYNOPSIS
Script to help developers capture traces of the PlayFab Party C++ client library
#>
#Requires -RunAsAdministrator
param(
    # Provides a descriptive label suffix (e.g., "ConnectAttempt1") to append
    # to the default output trace file name placed in the current directory,
    # in order to describe or distinguish what's being recorded in the
    # particular trace.
    # This parameter is required unless an -OutputFile file path parameter is
    # specified, in which case this parameter will be ignored.
    [string]$TraceLabel,

    # Provides the desired output file path where the result trace file will be
    # written.
    # If this parameter is not specified, then the separate -TraceLabel
    # parameter must be provided instead. If both this parameter and -TraceLabel
    # are specified, only this parameter is used.
    [string]$OutputFile,

    # Whether to include verbose transport entries in the trace file.
    # Defaults to false if not specified.
    [switch]$IncludeTransport
    )

if (($OutputFile -ne $null) -and ($OutputFile -ne ""))
{
    if (($TraceLabel -ne $null) -and ($TraceLabel -ne ""))
    {
        Write-Host "Ignoring trace label `"$TraceLabel`" because output file -OutputFile parameter specified."
    }

    $traceFileName = $OutputFile
    if (Test-Path $traceFileName)
    {
        $outputFileProperties = Get-ItemProperty $traceFileName
        $outputFilePath = $outputFileProperties.FullName
        throw "Output file `"$outputFilePath`" already exists! Please run again specifiying a different file name."
    }
}
else
{
    if (($TraceLabel -ne $null) -and ($TraceLabel -ne ""))
    {
        $traceFileName = "pfp_trace_$TraceLabel.etl"
        if (Test-Path $traceFileName)
        {
            $outputFileProperties = Get-ItemProperty $traceFileName
            $outputFilePath = $outputFileProperties.FullName
            throw "Output file `"$outputFilePath`"' already exists! Please run again specifiying a different trace label."
        }
    }
    else
    {
        throw "This script requires either the -TraceLabel or -OutputFile parameter to be specified! Run Get-Help -Detailed $PSCommandPath for usage."
    }
}

# PlayFab Party WPP - No verbose traces
$playfabPartyWppProvider = "provider={4E8F98A2-3DC0-4DD8-BB6F-7335068650A5} keywords=0xFFFFFFFFDCB48F9F level=5"
# XNUP WPP - No verbose traces
$xnupWppProvider = "provider={48EA4DB0-8D7E-419B-B465-E5B572F30305} keywords=0xFFFFFFFFFFFFFF9F level=5"
if ($IncludeTransport)
{
    # XRN WPP
    $xrnWppProvider = "provider={B895A8EE-76C9-4FB5-AF4B-6BEB6B4E05A0} keywords=0xFFFFFFFFFFFFFFFF level=5"
}
else
{
    $xrnWppProvider = ""
}
$providersString = @($playfabPartyWppProvider, $xnupWppProvider, $xrnWppProvider) -Join " "

# Attempt to determine if the netsh trace start command supports the
# 'bufferSize' parameter on this system by looking for the "bufferSize=" string
# in the command's help output text.
$netshTraceHelpOutput = [string](netsh trace start help)
if ($netshTraceHelpOutput.Contains("bufferSize="))
{
    $bufferSizeString = "buffersize=512"
}
else
{
    $bufferSizeString = ""
}

$netshStartCmd = "netsh trace start $bufferSizeString overwrite=no tracefile=`"$traceFileName`" report=disable $providersString"

Write-Host $netshStartCmd
cmd /c $netshStartCmd
if ($LASTEXITCODE -eq 0)
{
    Write-Host "Successfully started recording trace log."
    Write-Host ""
    Write-Host "Now please run your scenario."
    Read-Host "When complete, press 'Enter' to stop recording"

    cmd /c "netsh trace stop"
    if ($LASTEXITCODE -eq 0)
    {
        $outputFileProperties = Get-ItemProperty $traceFileName
        if ($outputFileProperties)
        {
            $outputFileSize = $outputFileProperties.Length
            $outputFilePath = $outputFileProperties.FullName
            Write-Host "Successfully wrote $outputFileSize byte trace file $outputFilePath"
        }
        else
        {
            Write-Error "Trace file $traceFileName was not successfully written!"
        }            
    }
    else
    {
        Write-Error "An error occurred attempting to stop the trace!"
    }
}
else
{
    Write-Error "An error occurred attempting to start the trace!"
}

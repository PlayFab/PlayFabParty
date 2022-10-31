#Requires -RunAsAdministrator
<#
.SYNOPSIS
Script to help developers capture traces of the PlayFab Party C++ client library
#>
param(
    # A label to append to the end of your tracefile to make it easier to identify
    # e.g. "Repro1"
    [Parameter(Mandatory=$true)]
    [string]$TraceLabel,
    # TODO: Expand this to support more platform types in the future.
    [ValidateSet("PC")]
    [string]$ClientType
    )

$traceFileName = "pfp_trace_$TraceLabel.etl"

# PlayFab Party WPP - No verbose traces
$playfabPartyWppProvider  = "provider={4E8F98A2-3DC0-4DD8-BB6F-7335068650A5} keywords=0xFFFFFFFFDCB48F9F level=5"
# XNUP WPP - No verbose traces
$xnupWppProvider = "provider={48EA4DB0-8D7E-419B-B465-E5B572F30305} keywords=0xFFFFFFFFFFFFFF9F level=5"

$providersString = @($playfabPartyWppProvider, $xnupWppProvider) -Join " "
$netshStartCmd = "netsh trace start buffersize=512 overwrite=no tracefile=`"$traceFileName`" report=disable $providersString"

Write-Host $netshStartCmd
cmd /c $netshStartCmd

Read-Host "Run your scenario. Hit any key to stop the trace"

cmd /c "netsh trace stop"

Write-Host "Trace file written to $traceFileName"

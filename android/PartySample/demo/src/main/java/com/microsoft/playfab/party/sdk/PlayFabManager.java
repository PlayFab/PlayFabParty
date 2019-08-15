package com.microsoft.playfab.party.sdk;

import android.util.Log;

import com.playfab.PlayFabClientAPI;
import com.playfab.PlayFabClientModels;
import com.playfab.PlayFabClientModels.*;
import com.playfab.PlayFabDataAPI;
import com.playfab.PlayFabDataModels;
import com.playfab.PlayFabDataModels.*;
import com.playfab.PlayFabErrors;
import com.playfab.PlayFabErrors.*;
import com.playfab.PlayFabSettings;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.FutureTask;

public class PlayFabManager {
    static final String TITLE_ID = "";

    public PlayFabManager() {
        PlayFabSettings.TitleId = TITLE_ID;
    }

    private EntityTokenResponse onLoginComplete(FutureTask<PlayFabResult<LoginResult>> loginTask) {
        PlayFabErrors.PlayFabResult<PlayFabClientModels.LoginResult> result = null;
        try {
            result = loginTask.get();
        } catch(Exception e) {
            System.out.println("Exception in PlayFab api call: " + e);
            return null;
        }

        if (result.Result != null) {
            PlayFabSettings.EntityToken = result.Result.EntityToken.EntityToken;
            return result.Result.EntityToken;
        } else if (result.Error != null) {
            Log.w(getClass().getSimpleName(), compileErrorsFromResult(result));
        }

        return null;
    }

    private <RT> String compileErrorsFromResult(PlayFabErrors.PlayFabResult<RT> result) {
        if (result == null || result.Error == null) {
            return null;
        }

        String errorMessage = "";
        if (result.Error.errorMessage != null) {
            errorMessage += result.Error.errorMessage;
        }
        if (result.Error.errorDetails != null) {
            for (Map.Entry<String, List<String>> pair : result.Error.errorDetails.entrySet()) {
                for (String msg : pair.getValue()) {
                    errorMessage += "\n" + pair.getKey() + ": " + msg;
                }
            }
        }
        return errorMessage;
    }
}

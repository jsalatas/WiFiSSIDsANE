/**
 * 
 */
package gr.ictpro.jsalatas.wifitags;

import java.util.List;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiManager;

import com.adobe.fre.FREContext;
import com.adobe.fre.FREFunction;
import com.adobe.fre.FREObject;
import com.adobe.fre.FREWrongThreadException;

/**
 * @author John Salatas <jsalatas@gmail.com>
 *
 */
public class WifiTagsFunction implements FREFunction {
    
    private WifiManager wifi;
    private Context appContext; 

    
    /* (non-Javadoc)
     * @see com.adobe.fre.FREFunction#call(com.adobe.fre.FREContext, com.adobe.fre.FREObject[])
     */
    @Override
    public FREObject call(FREContext ctx, FREObject[] args) {
	appContext = ctx.getActivity().getApplicationContext();
	FREObject returnValue = null;
	
	try {
	    returnValue = FREObject.newObject(getWifiTags());
	} catch (FREWrongThreadException e) {
	}
	
	return returnValue;
    }

    private String getWifiTags() {
	String res = "0";
	wifi =  (WifiManager) appContext.getSystemService(Context.WIFI_SERVICE);
	if (wifi.isWifiEnabled() == false) {
	    return "-1";
	}
	
	res = toJson(wifi.getScanResults());
	return res;
    }

    private String toJson(List<ScanResult> results) {
	StringBuilder sb = new StringBuilder();
	sb.append("{\"ssids\":[");
	boolean firstEntry = true;
	for(ScanResult result: results) {
	    if(firstEntry) {
		firstEntry = false;
	    } else {
		sb.append(", ");
	    }
	    sb.append("{\"name\":\"");
	    sb.append(result.SSID);
	    sb.append("\", \"strength\":");
	    sb.append(result.level);
	    sb.append(", \"connected\":");
	    sb.append(wifi.getConnectionInfo().getSSID().replace("\"", "").equals(result.SSID));
	    sb.append("}");
	}
	sb.append("]}");
	return sb.toString();
    }

    
}

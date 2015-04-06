/**
 * 
 */
package gr.ictpro.jsalatas.wifitags;

import java.util.HashMap;
import java.util.Map;

import com.adobe.fre.FREContext;
import com.adobe.fre.FREFunction;

/**
 * @author John Salatas <jsalatas@gmail.com>
 *
 */
public class WifiTagsContext extends FREContext {

    /* (non-Javadoc)
     * @see com.adobe.fre.FREContext#dispose()
     */
    @Override
    public void dispose() {
	// Do Nothing
    }

    /* (non-Javadoc)
     * @see com.adobe.fre.FREContext#getFunctions()
     */
    @Override
    public Map<String, FREFunction> getFunctions() {
	Map<String, FREFunction> functions = new HashMap<String, FREFunction>();
	functions.put("isSupported", new SupportedFunction());
	functions.put("getWifiTags", new WifiTagsFunction());
	return functions ;
    }

}

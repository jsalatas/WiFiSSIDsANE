/**
 * 
 */
package gr.ictpro.jsalatas.wifitags;

import com.adobe.fre.FREContext;
import com.adobe.fre.FREExtension;

/**
 * @author John Salatas <jsalatas@gmail.com>
 *
 */
public class WifiTags implements FREExtension {

    @Override
    public FREContext createContext(String arg0) {
	return new WifiTagsContext();
    }

    @Override
    public void dispose() {
	// Do Nothing

    }

    @Override
    public void initialize() {
	// TODO Auto-generated method stub

    }

}

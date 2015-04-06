/**
 * 
 */
package gr.ictpro.jsalatas.wifitags;

import com.adobe.fre.FREContext;
import com.adobe.fre.FREFunction;
import com.adobe.fre.FREObject;
import com.adobe.fre.FREWrongThreadException;

/**
 * @author John Salatas <jsalatas@gmail.com>
 *
 */
public class SupportedFunction implements FREFunction {

    /* (non-Javadoc)
     * @see com.adobe.fre.FREFunction#call(com.adobe.fre.FREContext, com.adobe.fre.FREObject[])
     */
    @Override
    public FREObject call(FREContext ctx, FREObject[] args) {
	FREObject returnValue = null;
	
	try {
	    returnValue = FREObject.newObject(true);
	} catch (FREWrongThreadException e) {
	}
	
	return returnValue;
    }

}

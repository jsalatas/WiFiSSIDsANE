/**
 * Copyright (C) 2015 John Salatas (jsalatas@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License v3 (LGPL-3) 
 * as published by the Free Software Foundation.
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

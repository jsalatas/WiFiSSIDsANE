/**
 * Copyright (C) 2015 John Salatas (jsalatas@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License v3 (LGPL-3) 
 * as published by the Free Software Foundation.
 *
 */
package gr.ictpro.jsalatas.ane.wifitags
{
	import flash.events.EventDispatcher;
	import flash.events.IEventDispatcher;
	import flash.external.ExtensionContext;
	
	public class WifiTags extends EventDispatcher
	{
		private var _ctx:ExtensionContext
		
		public function WifiTags(target:IEventDispatcher=null)
		{
			super(target);
			_ctx = ExtensionContext.createExtensionContext("gr.ictpro.jsalatas.ane.wifitags", null);
		}
		
		public function dispose():void
		{
			_ctx.dispose();
		}
		
		public function isSupported():Boolean
		{
			return _ctx.call("isSupported");
		}
		
		public function getWifiTags():Object 
		{
			return JSON.parse(_ctx.call("getWifiTags") as String);
		}
	}
}
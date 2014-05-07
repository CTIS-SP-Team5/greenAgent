package com.greenagent.app;

import android.os.Bundle;
import android.app.Activity;
import android.app.ListActivity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.Window;
import android.widget.ListView;

public class ViewSettings extends ListActivity {

private String []  locations = {"Temperature", "CO2", "Irrigation", "Light", "Soil Moisture"};
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setListAdapter(new SensorAdapter(this, locations));
	}
	
	@Override
	protected void onListItemClick(ListView lv, View view, int position, long id) {
		// Get the selected item and display it with Toast 
		String selectedValue = (String) getListAdapter().getItem(position);
		
		if(selectedValue=="Temperature")
		{
			Intent intent = new Intent(this, ViewSettingActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="CO2")
		{
			Intent intent = new Intent(this, ViewSettingActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Irrigation")
		{
			Intent intent = new Intent(this, ViewSettingActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Light")
		{
			Intent intent = new Intent(this, ViewSettingActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Soil Moisture")
		{
			Intent intent = new Intent(this, ViewSettingActivity.class);
			startActivity(intent);
		}
	
	}

}

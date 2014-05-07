package com.greenagent.app;

import android.os.Bundle;
import android.app.Activity;
import android.app.ListActivity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.Window;
import android.widget.ListView;

public class ActuatorControls extends ListActivity {

private String []  locations = {"Water Pump", "Heater", "Ventilation", "Lighting System","Alert Triggers"};
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setListAdapter(new ActuatorAdapter(this, locations));
	}
	
	@Override
	protected void onListItemClick(ListView lv, View view, int position, long id) {
		// Get the selected item and display it with Toast 
		String selectedValue = (String) getListAdapter().getItem(position);
		
		if(selectedValue=="Water Pump")
		{
			Intent intent = new Intent(this, ActuatorActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Heater")
		{
			Intent intent = new Intent(this, ActuatorActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Ventilation")
		{
			Intent intent = new Intent(this, ActuatorActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Lighting System")
		{
			Intent intent = new Intent(this, ActuatorActivity.class);
			startActivity(intent);
		}
		else if(selectedValue=="Alert Triggers")
		{
			Intent intent = new Intent(this, ActuatorActivity.class);
			startActivity(intent);
		}
		
	
	}

}

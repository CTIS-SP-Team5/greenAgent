package com.greenagent.app;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.Button;

public class Bilkent extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_bilkent);
		
		Button logoutButton = (Button)findViewById(R.id.button1);
		
		logoutButton.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //logout
	          }

	        });
		
		Button viewData = (Button)findViewById(R.id.Button01);
		
		viewData.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //viewdata
	          }

	        });
		
		Button manageUsers = (Button)findViewById(R.id.Button02);
		
		manageUsers.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //manageUsers
	          }

	        });
		
		Button viewSettings = (Button)findViewById(R.id.Button03);
		
		viewSettings.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //viewSettings
	          }

	        });
		
		Button actuatorControls = (Button)findViewById(R.id.Button04);
		
		actuatorControls.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //actuatorControls
	          }

	        });
		
		Button alerts = (Button)findViewById(R.id.Button05);
		
		alerts.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //alerts
	          }

	        });
		
		Button viewCamera = (Button)findViewById(R.id.Button06);
		
		viewCamera.setOnClickListener(new View.OnClickListener() {

	          @Override
	          public void onClick(View view) {
	            //viewCamera
	          }

	        });
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.bilkent, menu);
		return true;
	}

}

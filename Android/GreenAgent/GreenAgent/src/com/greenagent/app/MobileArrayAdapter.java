package com.greenagent.app;

import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class MobileArrayAdapter extends ArrayAdapter<String> {
	private Context context;
	private String[] values;
	private LayoutInflater inflater;

	public MobileArrayAdapter(Context context, String[] values) {
		super(context, R.layout.list_item, values);
		this.context = context;
		this.values = values;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		View rowView = convertView;
		if (rowView == null) {
			inflater = (LayoutInflater) context
					.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
			rowView = inflater.inflate(R.layout.list_item, parent, false);
		}

		TextView textView = (TextView) rowView.findViewById(R.id.label);
		ImageView imageView = (ImageView) rowView.findViewById(R.id.logo);

		textView.setText(values[position]);
		textView.setTextColor(Color.rgb(253, 105, 1));

		// Change icon based on name
		String s = values[position];

		if (s.equals("Incek"))
			imageView.setImageResource(R.drawable.ic_launcher);
		else if (s.equals("Bilkent"))
			imageView.setImageResource(R.drawable.ic_launcher);
		

		return rowView;
	}
}
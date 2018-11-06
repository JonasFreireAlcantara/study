package com.study.jonas.activitiesintents;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.RadioButton;

public class CourseChooserActivity extends AppCompatActivity {

    private RadioButton bcc = findViewById(R.id.radio_button_bcc);
    private RadioButton bsi = findViewById(R.id.radio_button_bcc);
    private RadioButton lc = findViewById(R.id.radio_button_bcc);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_course_chooser);
    }
}

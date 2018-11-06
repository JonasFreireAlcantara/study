package com.study.jonas.activitiesintents;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;

public class FormularyActivity extends AppCompatActivity {

    private Button button_chooser = findViewById(R.id.button_choose);

    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_formulary);

        button_chooser.setOnClickListener((v) -> {
            Intent intent = new Intent(this, CourseChooserActivity.class);
            intent.putExtra("actualCourse", button_chooser.getText().toString());
            startActivityForResult(intent, 1);
        });
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult();

        if(requestCode == 1 && resultCode == 2) {
            String courseName = data.getStringExtra("actualCourse");
            this.button_chooser.setText(courseName);
        }
    }
}

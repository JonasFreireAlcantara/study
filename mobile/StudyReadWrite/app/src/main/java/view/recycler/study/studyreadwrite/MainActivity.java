package view.recycler.study.studyreadwrite;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    // Write file to internal storage
    private void writeInternalStorage() {
        String filename = "my_first_file";
        String fileContent = "My first write to internal storage through Android platform";
        FileOutputStream fileOutputStream;

        try {
            fileOutputStream = openFileOutput(filename, Context.MODE_PRIVATE);
            fileOutputStream.write(fileContent.getBytes());
            fileOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    // Read file from internal storage
    private String readInternalStorage() {
        String filename = "my_first_file";
        String fileContent;
        FileInputStream fileInputStream;

        try {
            fileInputStream = openFileInput(filename);
            fileContent = fileInputStream.read(
            fileInputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}

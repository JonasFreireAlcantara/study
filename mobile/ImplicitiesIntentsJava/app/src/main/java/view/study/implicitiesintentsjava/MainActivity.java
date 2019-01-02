package view.study.implicitiesintentsjava;

import android.app.SearchManager;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void browseAction(View view) {
        String url = ((EditText)findViewById(R.id.edit_text_url)).getText().toString();
        Uri uri = null;
        try {
            uri = Uri.parse(url);
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
            this.fireIntent(intent);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public void searchAction(View view) {
        String expression = ((EditText)findViewById(R.id.edit_text_search)).getText().toString();
        Intent intent = new Intent(Intent.ACTION_SEARCH);
        intent.putExtra(SearchManager.QUERY, expression);
        fireIntent(intent);
    }


    private void fireIntent(Intent intent) {
        if(intent.resolveActivity(getPackageManager()) != null) {
            startActivity(intent);
        } else {
            Toast.makeText(this, "Problem to fire this intent", Toast.LENGTH_SHORT).show();
        }
    }


}

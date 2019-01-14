package view.study.implicitiesintentsmaps

import android.content.Intent
import android.net.Uri
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun coordinateSearchAction(view: View) {
        val mapsPackageString = "com.google.android.apps.maps"
        val latitude = findViewById<EditText>(R.id.edit_text_latitude).text.toString()
        val longitude = findViewById<EditText>(R.id.edit_text_longitude).text.toString()
        val label = findViewById<EditText>(R.id.edit_text_label).text.toString()

        if(latitude.isEmpty() || longitude.isEmpty()) {
            Toast.makeText(this, "You must fill both fields latitude and longitude", Toast.LENGTH_LONG).show()
            return
        }

        lateinit var uri: Uri
        if(label.isEmpty())
            uri = Uri.parse("geo:" + latitude + "," + longitude)
        else
            uri = Uri.parse("geo:0,0?q=" + latitude + "," + longitude + "(" + label + ")")
        val intent = Intent(Intent.ACTION_VIEW, uri)
        intent.setPackage(mapsPackageString)
        this.fireIntent(intent)
    }

    fun expressionSearchAction(view: View) {
        val mapsPackageString = "com.google.android.apps.maps"
        val expression = findViewById<EditText>(R.id.edit_text_expression).text.toString()

        if(expression.isEmpty()) {
            Toast.makeText(this, "You must fill the expression field", Toast.LENGTH_LONG).show()
            return
        }

        val uri = Uri.parse("geo:0,0?q=" + Uri.encode(expression))
        val intent = Intent(Intent.ACTION_VIEW, uri)
        intent.setPackage(mapsPackageString)
        this.fireIntent(intent)
    }

    private fun fireIntent(intent: Intent) {
        if(intent.resolveActivity(packageManager) != null)
            startActivity(intent)
        else
            Toast.makeText(this, "Problem to launch intent", Toast.LENGTH_SHORT).show()
    }
}

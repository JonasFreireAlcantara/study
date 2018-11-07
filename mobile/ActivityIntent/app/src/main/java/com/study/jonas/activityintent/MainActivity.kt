package com.study.jonas.activityintent

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    private var idButton : Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        button_choose.setOnClickListener {
            val intent = Intent(applicationContext, ChooseCourseActivity::class.java)
            intent.putExtra("idButton", idButton)
            startActivityForResult(intent, Directives.REQUEST.code)
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        if(requestCode == Directives.REQUEST.code && resultCode == Directives.RESPONSE.code && data != null) {
            idButton = data.getIntExtra("idButton", 0)
            button_choose.setText(idButton)
        }
    }
}

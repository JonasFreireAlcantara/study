package com.study.jonas.activityintent

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_choose_course.*

class ChooseCourseActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_choose_course)

        setPreviousSelecteOption(intent.getIntExtra("idButton", 0))

        select_button.setOnClickListener {
            val option = getIdSelectedOption()
            if(option == 0)
                return@setOnClickListener
            val it = Intent(applicationContext, MainActivity::class.java)
            it.putExtra("idButton", option)
            setResult(Directives.RESPONSE.code, it)
            finish()
        }

        select_button
    }

    private fun getIdSelectedOption() : Int {
        return if(bcc_option.isChecked) {R.string.bcc_text}
        else if(bsi_option.isChecked) {R.string.bsi_text}
        else if(lc_option.isChecked) {R.string.lc_text}
        else {0}
    }

    private fun setPreviousSelecteOption(option : Int) {
        if(option == R.string.bcc_text) bcc_option.setChecked(true)
        else if(option == R.string.bsi_text) bsi_option.setChecked(true)
        else if(option == R.string.lc_text) lc_option.setChecked(true)
    }

}

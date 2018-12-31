package view.recycler.study.moneycounter

import android.content.Intent
import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.view.View
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_coins.*
import kotlinx.android.synthetic.main.activity_main.*
import java.lang.NumberFormatException

class CoinsActivity: AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_coins)
    }

    fun coinsComputeAction(view: View) {
        var hundred = 0.0
        var fifty = 0.0
        var twentyFive = 0.0
        var ten = 0.0
        var five = 0.0

        try {
            hundred = coins_edit_text_hundred_cents.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            fifty = coins_edit_text_fifty_cents.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            twentyFive = coins_edit_text_twenty_five_cents.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            ten = coins_edit_text_ten_cents.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            five = coins_edit_text_five_cents.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        if( hundred < 0 || fifty < 0 || twentyFive < 0 || ten < 0 || five < 0) {
            val toast = Toast.makeText(this, "The number fields must be greater than 0", Toast.LENGTH_SHORT)
            toast.show()
        }

        this.setResult( hundred * 1 +
                fifty * 0.5 +
                twentyFive * 0.2 +
                ten * 0.1 +
                five * 0.05 )
    }


    private fun setResult(result: Double) {
        val intent = Intent()
        intent.putExtra(Constant.COINS_VALUE, result)
        setResult(Constant.RESULT_COINS_CODE, intent)
        finish()
    }
}
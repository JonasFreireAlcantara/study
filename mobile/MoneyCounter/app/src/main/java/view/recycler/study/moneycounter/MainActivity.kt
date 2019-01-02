package view.recycler.study.moneycounter

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*
import java.lang.NumberFormatException

class MainActivity : AppCompatActivity() {
    private var coinsResult = 0.0
    private var bankNotesResult = 0.0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        this.setResultBanknotes(this.bankNotesResult)
        this.setResultCoins(this.coinsResult)
        this.setResultTotal(this.coinsResult + this.bankNotesResult)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        if(requestCode == Constant.REQUEST_COINS_CODE && resultCode == Constant.RESULT_COINS_CODE && data != null)
            this.coinsResult = data!!.getDoubleExtra(Constant.COINS_VALUE, 0.0)

        this.setResultCoins(this.coinsResult)
        this.setResultTotal(this.coinsResult + this.bankNotesResult)
    }


    fun cleanCoinsAction(view: View) {
        this.coinsResult = 0.0

        this.setResultCoins(this.coinsResult)
        this.setResultTotal(this.bankNotesResult)
        Toast.makeText(this, getString(R.string.toast_coins_cleared), Toast.LENGTH_SHORT).show()
    }

    fun coinsAction(view: View) {
        val intent = Intent(this, CoinsActivity::class.java)
        startActivityForResult(intent, Constant.REQUEST_COINS_CODE)
    }


    fun computeAction(view: View) {
        var hundred = 0.0
        var fifty = 0.0
        var twenty = 0.0
        var ten = 0.0
        var five = 0.0
        var two = 0.0

        try {
            hundred = edit_text_hundred.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            fifty = edit_text_fifty.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            twenty = edit_text_twenty.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            ten = edit_text_ten.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            five = edit_text_five.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        try {
            two = edit_text_two.text.toString().toDouble()
        } catch (e: NumberFormatException) { }

        if( hundred < 0 || fifty < 0 || twenty < 0 || ten < 0 || five < 0 || two < 0) {
            val toast = Toast.makeText(this, "The number fields must be greater than 0", Toast.LENGTH_SHORT)
            toast.show()
        }

        this.bankNotesResult = hundred * 100 + fifty * 50 + twenty * 20 + ten * 10 + five * 5 + two * 2
        this.setResultBanknotes(this.bankNotesResult)
        this.setResultTotal(this.bankNotesResult + this.coinsResult)
    }


    private fun setResultBanknotes(result: Double) {
        text_view_result_banknotes.text = "R$ %.2f".format(result)
    }

    private fun setResultCoins(result: Double) {
        text_view_result_coins.text = "R$ %.2f".format(result)
    }

    private fun setResultTotal(result: Double) {
        text_view_result_total.text = "R$ %.2f".format(result)
    }
}

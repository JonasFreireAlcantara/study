package view.study.firebasedemo

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import com.google.firebase.auth.FirebaseAuth
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    private lateinit var auth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        auth = FirebaseAuth.getInstance()

        Log.d("Problem", "Here")

        button_sign_up.setOnClickListener {

            auth.createUserWithEmailAndPassword(edit_text_user.text.toString(), edit_text_password.text.toString())
                .addOnCompleteListener(this) { task ->

                    if(task.isSuccessful) {
                        Log.d("STUDY", "createUserWithEmail:sucess")
                        Toast.makeText(this, "Sucessfull Sign Up", Toast.LENGTH_SHORT).show()
                    } else {
                        Log.w("Study", "createUserWithEmail:failure")
                        Toast.makeText(this, "Failure to Sign Up", Toast.LENGTH_SHORT).show()
                    }
                }
        }




        button_sign_in.setOnClickListener {

            auth.signInWithEmailAndPassword(edit_text_user.text.toString(), edit_text_password.text.toString())
                .addOnCompleteListener(this) { task ->

                    if(task.isSuccessful) {
                        Log.d("STUDY", "Login:sucessfull")
                        Toast.makeText(this, "Login Sucessfull", Toast.LENGTH_SHORT).show()
                    }

                }

        }


    }
}

package view.recycler.study.studyfragmentskotlin

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView

class MainActivity : AppCompatActivity() {
    lateinit var recyclerView: RecyclerView
    lateinit var layoutManager: RecyclerView.LayoutManager
    lateinit var adapter: RecyclerView.Adapter<*>
    lateinit var listOfPerson: ArrayList<Person>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        listOfPerson = ArrayList<Person>()
        for( k in 0..10) {
            listOfPerson.add(Person("Jonas", "Freire"))
            listOfPerson.add(Person("Jasom", "Freire"))
            listOfPerson.add(Person("Edson", "Marques"))
            listOfPerson.add(Person("Maria", "Ida"))
            listOfPerson.add(Person("Vinícius", "Alcantara"))
        }

        recyclerView = findViewById(R.id.recycler_view)
        layoutManager = LinearLayoutManager(this)
        adapter = MyAdapter(listOfPerson)

        recyclerView.adapter = adapter
        recyclerView.layoutManager = layoutManager
    }
}

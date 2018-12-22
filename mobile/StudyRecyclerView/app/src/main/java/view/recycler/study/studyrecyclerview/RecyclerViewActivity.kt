package view.recycler.study.studyrecyclerview

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.service.autofill.Dataset
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView

class RecyclerViewActivity : AppCompatActivity() {
    private lateinit var recyclerView: RecyclerView
    private lateinit var viewAdapter: RecyclerView.Adapter<*>
    private lateinit var viewManager: RecyclerView.LayoutManager

    private lateinit var dataset: ArrayList<Person>




    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_recycler_view)

        loadDataset()

        viewManager = LinearLayoutManager(this)
        viewAdapter = MyAdapter(this.dataset)

        recyclerView = findViewById(R.id.recycler_view_study)

//        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = viewManager
        recyclerView.adapter = viewAdapter
    }





    private fun loadDataset() {
        dataset = ArrayList<Person>()
        for(c in 0..100) {
            dataset.add(Person("Jonas", "Freire"))
            dataset.add(Person("Maria", "Ida"))
            dataset.add(Person("Jasom", "Freire"))
            dataset.add(Person("Edson", "Marques"))
        }
    }
}

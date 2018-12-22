package view.recycler.study.studyrecyclerview

import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView

class MyAdapter(private val dataset: ArrayList<Person>) :
    RecyclerView.Adapter<MyAdapter.ViewHolder>() {

    class ViewHolder(val view: View) : RecyclerView.ViewHolder(view) {
        var text_1 = view.findViewById<TextView>(R.id.text_view_one)
        var text_2 = view.findViewById<TextView>(R.id.text_view_two)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyAdapter.ViewHolder {
        val viewItem = LayoutInflater.from(parent.context).
            inflate(R.layout.recycler_view_item, parent, false) as View

        return MyAdapter.ViewHolder(viewItem)
    }

    override fun onBindViewHolder(viewHolder: ViewHolder, position: Int) {
        val person = dataset[position]

        viewHolder.text_1.text = person.firstName
        viewHolder.text_2.text = person.lastName
    }

    override fun getItemCount() = this.dataset.size
}
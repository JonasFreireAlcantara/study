package view.recycler.study.studyfragmentskotlin

import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView



class MyAdapter(var dataset: ArrayList<Person>) : RecyclerView.Adapter<MyAdapter.MyViewHolder>() {

    class MyViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        var textViewFirstName: TextView = view.findViewById(R.id.text_view_first_name)
        var textViewLastName: TextView = view.findViewById(R.id.text_view_last_name)
    }


    override fun onCreateViewHolder(viewGroup: ViewGroup, p1: Int): MyViewHolder {
        val viewItem = LayoutInflater.from(viewGroup.context).inflate(R.layout.item, viewGroup, false)
        return MyViewHolder(viewItem)
    }


    override fun onBindViewHolder(myViewHolder: MyViewHolder, position: Int) {
        val person = dataset.get(position)

        myViewHolder.textViewFirstName.text = person.firstName
        myViewHolder.textViewLastName.text = person.lastName
    }


    override fun getItemCount(): Int {
        return dataset.size
    }
}
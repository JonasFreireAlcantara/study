package view.recycler.study.studyfragments;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.ArrayList;

import view.recycler.study.studyfragments.beans.Person;

public class PersonToListAdapter extends RecyclerView.Adapter<PersonToListAdapter.ViewHolder> {
    private ArrayList<Person> mDataSet;

    public PersonToListAdapter(ArrayList<Person> dataset) {
        mDataSet = dataset;
    }


    @Override
    public PersonToListAdapter.ViewHolder onCreateViewHolder(ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.list_item_person, viewGroup, false);

        TextView firstName = view.findViewById(R.id.text_view_first_name);
        TextView lastName = view.findViewById(R.id.text_view_last_name);

        return new PersonToListAdapter.ViewHolder(firstName, lastName);
    }


    @Override
    public void onBindViewHolder(ViewHolder viewHolder, int position) {
        Person person = mDataSet.get(position);

        viewHolder.firstName.setText(person.firstName);
        viewHolder.lastName.setText(person.lastName);
    }


    @Override
    public int getItemCount() {
        return mDataSet.size();
    }


    public static class ViewHolder extends RecyclerView.ViewHolder {
        public TextView firstName;
        public TextView lastName;
        public ViewHolder(TextView firstName, TextView lastName) {
            super(firstName);
            this.firstName = firstName;
            this.lastName = lastName;
        }
    }
}

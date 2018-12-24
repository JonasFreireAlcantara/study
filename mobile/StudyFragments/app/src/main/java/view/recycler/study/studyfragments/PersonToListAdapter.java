package view.recycler.study.studyfragments;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

import view.recycler.study.studyfragments.beans.Person;

public class PersonToListAdapter extends RecyclerView.Adapter<PersonToListAdapter.MyViewHolder> {
    private ArrayList<Person> mDataSet;

    public PersonToListAdapter(ArrayList<Person> dataset) {
        mDataSet = dataset;
    }


    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.list_item_person_image, viewGroup, false);

        return new MyViewHolder(view);
    }


    @Override
    public void onBindViewHolder(MyViewHolder viewHolder, int position) {
        Person person = mDataSet.get(position);

        viewHolder.personImage.setImageBitmap(person.image);
        viewHolder.firstName.setText(person.firstName);
    }


    @Override
    public int getItemCount() {
        return mDataSet.size();
    }


    public static class MyViewHolder extends RecyclerView.ViewHolder {
        public ImageView personImage;
        public TextView firstName;
        public MyViewHolder(View view) {
            super(view);
            this.personImage = (ImageView) view.findViewById(R.id.image_view_person);
            this.firstName = (TextView) view.findViewById(R.id.text_view_first_name);
        }
    }
}

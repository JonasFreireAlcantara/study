package view.recycler.study.studyfragments;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.ArrayList;

import view.recycler.study.studyfragments.beans.Person;

public class ListPersonFragment extends Fragment {
    private ArrayList<Person> listOfPersons;
    private RecyclerView recyclerView;
    private RecyclerView.Adapter adapter;
    private RecyclerView.LayoutManager layoutManager;


    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        listOfPersons = new ArrayList<Person>();
        for(int k = 0; k < 10; k++) {
            listOfPersons.add(new Person("Jonas", "Barros", 21, "Male", "Not Married"));
            listOfPersons.add(new Person("Jasom", "Barros", 30, "Male", "Married"));
            listOfPersons.add(new Person("Edson", "Barros", 58, "Male", "Married"));
            listOfPersons.add(new Person("Maria", "Barros", 54, "Female", "Married"));
            listOfPersons.add(new Person("Silas", "Araújo", 20, "Male", "Not Married"));
            listOfPersons.add(new Person("Isaac", "Santos", 19, "Male", "Not Married"));
        }

        recyclerView = getActivity().findViewById(R.id.recycler_view);
        layoutManager = new LinearLayoutManager(getActivity());
        adapter = new PersonToListAdapter(listOfPersons);

        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setAdapter(adapter);
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_layout_list, container, false);
    }




}

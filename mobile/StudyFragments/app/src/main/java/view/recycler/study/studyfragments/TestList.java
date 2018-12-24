package view.recycler.study.studyfragments;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;

import java.util.ArrayList;

import view.recycler.study.studyfragments.beans.Person;

public class TestList extends AppCompatActivity {
    private ArrayList<Person> listOfPersons;
    private RecyclerView recyclerView;
    private RecyclerView.Adapter adapter;
    private RecyclerView.LayoutManager layoutManager;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.road);

        listOfPersons = new ArrayList<Person>();
        for(int k = 0; k < 10; k++) {
            listOfPersons.add(new Person("Jonas", "Barros", 21, "Male", "Not Married", bitmap));
            listOfPersons.add(new Person("Jasom", "Barros", 30, "Male", "Married", bitmap));
            listOfPersons.add(new Person("Edson", "Barros", 58, "Male", "Married", bitmap));
            listOfPersons.add(new Person("Maria", "Barros", 54, "Female", "Married", bitmap));
            listOfPersons.add(new Person("Silas", "Araújo", 20, "Male", "Not Married", bitmap));
            listOfPersons.add(new Person("Isaac", "Santos", 19, "Male", "Not Married", bitmap));
        }

        recyclerView = findViewById(R.id.recycler_view_copy);
        layoutManager = new LinearLayoutManager(this);
        adapter = new PersonToListAdapter(listOfPersons);

        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setAdapter(adapter);
    }
}

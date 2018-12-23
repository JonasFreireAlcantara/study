package view.recycler.study.studyfragments;

import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();

        fragmentTransaction.add(R.id.activity_main_frame_layout_list, new ListPersonFragment());
        fragmentTransaction.commit();

//        FragmentManager fragmentManager = getSupportFragmentManager();
//
//        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
//        fragmentTransaction.add(R.id.activity_main_frame_layout_image, new ImageFragment());
//
//        if(findViewById(R.id.activity_main_frame_layout_name) != null)
//            fragmentTransaction.add(R.id.activity_main_frame_layout_name, new ImageNameFragment());
//
////        Way to discover the display orientation ...
////        System.out.printf("Landscape = %s\n", getResources().getBoolean(R.bool.screen_orientation_landscape));
//
//        fragmentTransaction.commit();
    }
}

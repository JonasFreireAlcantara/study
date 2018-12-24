package view.recycler.study.studyfragments.beans;

import android.graphics.Bitmap;

public class Person {

    public String firstName;
    public String lastName;
    public int age;
    public String sex;
    public String maritalStates;
    public Bitmap image;

    public Person(String firstName, String lastName, int age, String sex, String maritalStates) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.sex = sex;
        this.maritalStates = maritalStates;
    }

    public Person(String firstName, String lastName, int age, String sex, String maritalStates, Bitmap image) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.sex = sex;
        this.maritalStates = maritalStates;
        this.image = image;
    }
}

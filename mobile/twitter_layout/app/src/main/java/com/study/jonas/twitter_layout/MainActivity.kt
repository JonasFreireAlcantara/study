package com.study.jonas.twitter_layout

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.design.widget.TabLayout
import android.support.v4.view.ViewPager
import android.view.MenuInflater
import android.view.View
import android.widget.PopupMenu

class MainActivity : AppCompatActivity() {

    private lateinit var adapter: TabAdapter
    private lateinit var tabLayout: TabLayout
    private lateinit var viewPager: ViewPager

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        supportActionBar?.setDisplayShowTitleEnabled(false)

        viewPager = findViewById(R.id.viewPager)
        tabLayout = findViewById(R.id.tabLayout)

        adapter = TabAdapter(supportFragmentManager)
        adapter.addFragment(TabHome(), "Home")
        adapter.addFragment(TabDiscover(), "Discover")
        adapter.addFragment(TabActivity(), "Activity")

        viewPager.adapter = this.adapter
        tabLayout.setupWithViewPager(this.viewPager)
    }

    fun showPopup(v: View) {
        val popup = PopupMenu(this, v)
        val inflater: MenuInflater = popup.menuInflater
        inflater.inflate(R.menu.menu_popup, popup.menu)
        popup.show()
    }
}

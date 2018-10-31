package com.study.jonas.twitter_layout

import android.support.v4.app.Fragment
import android.support.v4.app.FragmentManager
import android.support.v4.app.FragmentStatePagerAdapter

class TabAdapter(fm : FragmentManager) : FragmentStatePagerAdapter(fm) {

    private var mFragmentList : MutableList<Fragment> = mutableListOf()
    private var mFragmentTitleList : MutableList<String> = mutableListOf()


    override fun getItem(position: Int): Fragment {
        return mFragmentList.get(position)
    }

    fun addFragment(fragment : Fragment, title : String) {
        mFragmentList.add(fragment)
        mFragmentTitleList.add(title)
    }

    override fun getPageTitle(position: Int): CharSequence? {
        return mFragmentTitleList.get(position)
    }

    override fun getCount(): Int {
        return mFragmentList.size
    }

}
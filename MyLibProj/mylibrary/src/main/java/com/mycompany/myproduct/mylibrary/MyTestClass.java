package com.mycompany.myproduct.mylibrary;

import android.widget.Toast;
import android.app.Activity;

public class MyTestClass
{
    public static void showSimple(final Activity a, final String toast) {
        a.runOnUiThread(new Runnable() {
            public void run() {
                Toast.makeText(a.getApplicationContext(), toast, Toast.LENGTH_LONG).show();
            }
        });
    }
}

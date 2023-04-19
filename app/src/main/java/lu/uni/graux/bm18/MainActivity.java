package lu.uni.graux.bm18;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.provider.Settings;
import android.widget.TextView;

import lu.uni.graux.bm18.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private String imei;
    private String notImei;
    private String notImei2;

    static {
        System.loadLibrary("bm18");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        this.notImei = "Hello";

        this.imei = Settings.Secure.getString(this.getApplicationContext().getContentResolver(), Settings.Secure.ANDROID_ID);

        this.fieldCopyUsingJNI();

        TextView tv = binding.sampleText;
        tv.setText(this.notImei + "\n" + this.notImei2);
    }

    public native void fieldCopyUsingJNI();
}
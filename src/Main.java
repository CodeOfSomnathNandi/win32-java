import com.kernel.*;

public class Main {
    public static void main(String[] args) {
        SimpleFunctions.SetLastError(2);
       System.out.println(SimpleFunctions.GetLastError());
       System.out.println();
    }
}

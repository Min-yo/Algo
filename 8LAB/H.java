import java.io.*;

public class H {

    public static void main(String[] args) throws IOException
    {
        class Main {
            String longestCommonSubstring(String S1, String S2)
            {
                int Start = 0;
                int Max = 0;
                for (int i = 0; i < S1.length(); i++)
                {
                    for (int j = 0; j < S2.length(); j++)
                    {
                        int x = 0;
                        while (S1.charAt(i + x) == S2.charAt(j + x))
                        {
                            x++;
                            if (((i + x) >= S1.length()) || ((j + x) >= S2.length())) break;
                        }
                        if (x > Max)
                        {
                            Max = x;
                            Start = i;
                        }
                    }
                }
                return S1.substring(Start, (Start + Max));
            }

            int hash(String pat){
                int M = pat.length();

                int h = 1;
                int d = 101;
                int q = 11;
                int p=0;

                for (int i = 0; i < M - 1; i++)
                    h = (h * d) % q;
                for (int i = 0; i < M; i++) {
                    p = (d * p + pat.charAt(i)) % q;
                }
                return p;
            }
        }

        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());


        String txt1 = br.readLine();
        String txt2;
        String newPat,pat = txt1;

        int hashPat= main.hash(txt1);
        int min = txt1.length();

        for(int i=1;i<n;i++){
            txt2 = br.readLine();
            newPat = main.longestCommonSubstring(txt1,txt2);
            if(hashPat != main.hash(newPat)){
                if(min > newPat.length()){
                    hashPat = main.hash(newPat);
                    pat = newPat;
                    min = newPat.length();
                }
            }
            txt1 = txt2;
        }
        System.out.println(pat);

    }

}

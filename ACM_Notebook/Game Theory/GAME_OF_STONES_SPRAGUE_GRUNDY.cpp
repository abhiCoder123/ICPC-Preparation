   // Game of Stones - Solution 1 - Sprague Grundy Theorem (Practice)

    #include <bits/stdc++.h>
    using namespace std;
     

    /*
    An array to store the grundy numbers. 
    Since the number of stones on any pile is at most 60 we take a sg of size >= 60 .
    */ 


    int sg[66]; 
    	
    int main () {

    	/*
    	There exists a pattern in the grundy numbers for this particular problem.
    	sg[1]=1 , sg[2]=1 ;
    	sg[3]= 2 , sg[4]= 2 , sg[5] = 2;
    	sg[6]=3 , sg[7] = 3 , sg[8] = 3 , sg[9] = 3  and so on.

    	ie., 1 is repeated twice , 2 is repeated thrice and so on

    	so we calculate grundy numbers based on above observation.
    	*/

    	int now = 1, num = 2, t = num;
    	while(now <= 60) {
    		sg[now ++] = num - 1;
    		if(!(-- t)) ++ num, t = num;
    	}

    	/*for(int i=1;i<=60;i++)
    		cout<<sg[i]<<endl;
		*/
		
    	int n; scanf("%d", &n);  // number of piles
    	int ans = 0;
    	for(int i = 1; i <= n; ++ i) {
    		int x; scanf("%d", &x);   // number of stones on each pile
    		ans ^= sg[x];  // Applying Sprague - Grundy Theorem

    		/*
    		Sprague - Grundy Theorem for Impartial Games
    		RESULT= XOR(sg[state_1],sg[state_2],...)

    		if Result is 0 , you lose , else you win (if you start first)
    		*/
    	}
    	puts(ans ? "NO" : "YES");
    	return 0;
    }


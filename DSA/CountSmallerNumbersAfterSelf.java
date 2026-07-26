import java.util.*;

public class CountSmallerNumbersAfterSelf {


    static void mergeSort(int[] nums, int[] indexes, int[] ans, int low, int high) {

        if(low >= high)
            return;


        int mid = low + (high-low)/2;


        mergeSort(nums,indexes,ans,low,mid);
        mergeSort(nums,indexes,ans,mid+1,high);


        merge(nums,indexes,ans,low,mid,high);
    }



    static void merge(int[] nums,int[] indexes,int[] ans,int low,int mid,int high){

        int[] temp = new int[high-low+1];


        int left = low;
        int right = mid+1;

        int count = 0;
        int k = 0;


        while(left<=mid && right<=high){

            if(nums[indexes[right]] < nums[indexes[left]]){

                count++;

                temp[k++] = indexes[right++];

            }
            else{

                ans[indexes[left]] += count;

                temp[k++] = indexes[left++];
            }
        }


        while(left<=mid){

            ans[indexes[left]] += count;

            temp[k++] = indexes[left++];
        }


        while(right<=high){

            temp[k++] = indexes[right++];
        }


        for(int i=low;i<=high;i++){
            indexes[i]=temp[i-low];
        }
    }



    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();

        int[] nums=new int[n];

        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }


        int[] indexes=new int[n];

        int[] ans=new int[n];


        for(int i=0;i<n;i++){
            indexes[i]=i;
        }


        mergeSort(nums,indexes,ans,0,n-1);


        for(int x:ans){
            System.out.print(x+" ");
        }

    }
}
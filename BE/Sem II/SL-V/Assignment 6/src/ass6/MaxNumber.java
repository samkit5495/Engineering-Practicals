package ass6;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileStatus;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class MaxNumber {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Configuration conf=new Configuration();
		Job job=new Job(conf,"ma num");
		job.setJarByClass(MaxNumber.class);
		job.setMapperClass(MapNumber.class);
		job.setNumReduceTasks(0);
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(IntWritable.class);
		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));
		FileSystem fs=FileSystem.get(conf);
		fs.delete(new Path(args[1]));
		job.waitForCompletion(true);
		
		FileStatus status[]=fs.listStatus(new Path(args[1]));
		for(FileStatus f : status)
		{
			System.out.println(f.getPath());
			fs.copyToLocalFile(false, f.getPath(), new Path("/home/hduser/"+args[1]));
		}
		System.out.println("lineno\tnum1\tnum2\tmax");
		Scanner sc=new Scanner(new File("/home/hduser/"+args[1]));
		int temp;
		ArrayList<Integer> maxNumbers=new ArrayList<>();
		while(sc.hasNext())
		{
			System.out.println(sc.next()+"\t"+sc.next()+"\t"+sc.next()+"\t"+(temp=sc.nextInt()));
			maxNumbers.add(temp);
		}
		System.out.println("Maximum No:"+Collections.max(maxNumbers));
		sc.close();
	}

}

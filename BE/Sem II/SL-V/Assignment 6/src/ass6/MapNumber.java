package ass6;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class MapNumber extends Mapper<LongWritable, Text, Text, IntWritable>{
	
	int lineNumber=1;
	@Override
	protected void map(LongWritable key, Text value, Mapper<LongWritable, Text, Text, IntWritable>.Context context)
			throws IOException, InterruptedException {
		// TODO Auto-generated method stub
		String words[]=value.toString().split(",");
		int n1=Integer.parseInt(words[0]);
		int n2=Integer.parseInt(words[1]);
		int max=n2;
		if(n1>n2)
			max=n1;
		context.write(new Text(lineNumber++ +" "+n1+" "+n2), new IntWritable(max));
	}

}

import java.util.Scanner;

import javax.persistence.Query;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class Main {

	public static void insert(EntityManager em)
	{
		em.getTransaction().begin();
		em.persist(new Student(1,"Samkit",100));
		em.persist(new Student(2,"Aish",99));
		em.persist(new Student(3,"Prachin",80));
		em.persist(new Student(4,"Prateek",79));
		em.persist(new Student(5,"Neena",75));
		em.persist(new Student(6,"Abha",66));
		em.persist(new Student(7,"Priyanka",30));
		em.persist(new Student(8,"Minal",40));
		em.getTransaction().commit();
	}
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		EntityManagerFactory emf= Persistence.createEntityManagerFactory("$objectdb/db/sam.odb");
		EntityManager em=emf.createEntityManager();
		System.out.println("Enter 1 to insert else 0");
		if(new Scanner(System.in).nextInt()==1)
			insert(em);
		Query q1=em.createQuery("select count(s) from Student s");
		System.out.println("Q1: "+q1.getSingleResult());
		
		Query q2=em.createQuery("select name from Student");
		System.out.println("Q2: "+q2.getResultList());
		
		Query sq3=em.createQuery("select max(marks) from Student s");
		Query q3=em.createQuery("select name from Student where marks = "+sq3.getSingleResult());
		System.out.println("Q3: "+q3.getSingleResult());

		Query q4=em.createQuery("select name from Student where marks=66");
		System.out.println("Q4: "+q4.getSingleResult());

		Query q5=em.createQuery("select rollNo from Student where name='Minal'");
		System.out.println("Q5: "+q5.getSingleResult());

		Query q6=em.createQuery("select rollNo from Student where marks > 74");
		System.out.println("Q6: "+q6.getResultList());

		Query sq7=em.createQuery("select min(marks) from Student s");
		Query q7=em.createQuery("select name from Student where marks = "+sq7.getSingleResult());
		System.out.println("Q7: "+q7.getSingleResult());

		Query q8=em.createQuery("select avg(marks) from Student");
		System.out.println("Q8: "+q8.getSingleResult());

		Query q9=em.createQuery("select name from Student order by marks");
		System.out.println("Q9: "+q9.getResultList());

		Query q10=em.createQuery("select name from Student where marks between 68 and 76");
		System.out.println("Q10: "+q10.getResultList());

		
	}

}

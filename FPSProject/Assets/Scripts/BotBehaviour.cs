using UnityEngine;
using System.Collections;

public class BotBehaviour : MonoBehaviour {

	enum State
	{
		AGRESSIVE,//atira
		NEUTRAL,//para
		DEFENSIVE//corre
	};
	
	State currentState = State.NEUTRAL;
	
	Rigidbody rb;
	
	
	
	void Start () 
	{
		rb = GetComponent<Rigidbody>();
		//starta a corrotina que vai checar os estados
		StartCoroutine(CheckState());
		
			
	}
	IEnumerator CheckState()
	{
		while(true)
		{
			if(currentState == State.NEUTRAL)
				Stop();
			else if (currentState == State.AGRESSIVE)
				Shoot();
			else if (currentState == State.DEFENSIVE)
				MoveForward();
				
			
			yield return new WaitForSeconds(1.0f);
		}
	}
	void Stop()
	{
		rb.velocity = Vector3.zero;
		//precisa parar de atirar ainda
	}
	void Shoot()
	{
		//atira
	}
	
	void MoveForward()
	{
		
		rb.velocity = Vector3.forward * 10.0f;
			
	}
	
	
	
}

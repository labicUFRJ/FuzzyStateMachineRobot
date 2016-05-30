using UnityEngine;
using System.Collections;

public class BotData : MonoBehaviour {

	public uint ammo;
	public float healthPoints;
	
	void Start ()
	{
		ammo = Constants.MAX_AMMO;
		healthPoints = Constants.MAX_HEALTH;
	}
	
	
	
}


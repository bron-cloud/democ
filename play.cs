using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class play: MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown("space"))
        {
            GetComponent<Rigidbody>().velocity = new Vector3(0, 7, 0);
        }
    }
}

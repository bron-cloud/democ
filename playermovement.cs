using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playermovement
    : MonoBehaviour
{
    public float moveSpeed = 5f;
    public float jumpForce = 10f;
    public int maxJumps = 2;

    private int jumpsLeft;
    private Rigidbody2D rb;
    private bool isGrounded;
    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        jumpsLeft = maxJumps;
    }

    // Update is called once per frame
    void Update()
    {
        if (rb.velocity.y == 0)
        {
            isGrounded = true;
            jumpsLeft = maxJumps; // ������Ծ����  
        }
        else
        {
            isGrounded = false;
        }
        float moveInput = Input.GetAxis("Horizontal");
        bool jumpInput = Input.GetButtonDown("Jump");

        // �ƶ�  
        rb.velocity = new Vector2(moveInput * moveSpeed, rb.velocity.y);

        // ��Ծ  
        if (jumpInput && isGrounded)
        {
            rb.velocity = new Vector2(rb.velocity.x, jumpForce);
            jumpsLeft--;
            isGrounded = false; // ������ٽӵ�  
        }
        else if (jumpInput && jumpsLeft > 0 && !isGrounded)
        {
            rb.velocity = new Vector2(rb.velocity.x, jumpForce);
            jumpsLeft--;
        }
    }
}
        
        
    



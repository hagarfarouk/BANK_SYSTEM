#ifndef CGP_INTERFACE_H_
#define CGP_INTERFACE_H_


#define Null ((void*)0)
typedef struct Node Node;

  void add(Node* ptr);
 // void get_grd_id(Node* ptr);
  //Node *create(char* , char* , u8 , u32 , u32  );
  Node *search(u32 value);
  void update_status(u32 _id,int st);
  void update_balance(u32 _id ,u32 cash ,char x );
  void update_pw(u32 _id,u32 password);
  int find_id(u32 _id);
  int find_balance(u32 _id);
  void create(char* n, char* add, u8 old, u32 value, char* national_id, char* gid );
  u32 user_id();
  void admin();
  void client();



#endif /* GRAD_PROJ_INTERFACE_H_ */

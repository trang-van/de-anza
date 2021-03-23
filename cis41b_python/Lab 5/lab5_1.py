'''
Lab 5- Sockets

Trang Van
CIS 41B

Description:

'''
import multiprocessing as mp 
import socket
import time
import pickle

HOST = 'localhost'
PORT = 4540

'''
def highChild(q):
    data = q.get()
    print('passed in: ', data)
    while data != 0:
        data += 1
        print('data inc: ', data)
        q.put(data)
        q.get()
        
def highLevel(): 
    x = 0
    x += 1
    q = mp.Queue()
    
    p = mp.Process(target = highChild , args = (q,)) # child process
    p.start()    
    
    q.put(x)

    #print(q.get())
    
    x = 1
    start = time.process_time()
    
    for i in range(10000):
        x += 1
        q.put(x)
        q.get()
        
    transfer = q.get()
    elapsed = time.process_time() - start
    
    print('\nElapsed time:', elapsed)
    
    print(transfer)
    
    return transfer/elapsed
'''

#Client
def lowChild():
        
    with socket.socket() as s:
        s.connect((HOST, PORT))
        print("Client connect to:", HOST, "port:", PORT)
        
    
        mesg = input("Enter message to send or q to quit: ")
        s.send(mesg.encode('utf-8'))
        while mesg != 'q':
            fromServer = s.recv(1024).decode('utf-8')
            print("Received from server:", fromServer)
            mesg = input("Enter message to send or q to quit: ")
            s.send(mesg.encode('utf-8'))        
        '''
        data = s.recv(1024)
        while data != 0:
            print('Recieved:', data)
            data += 1
            s.send(data)
        '''   
           
#Server
def lowLevel():
    server= socket.socket()
    p = mp.Process(target = lowChild)
    p.start()
    server.bind((HOST, PORT))   #Address for server
    print("Server hostname:", HOST, "port:", PORT)
    
    server.listen()
    (conn, addr) = server.accept()  

    while True:
        fromClient = conn.recv(1024).decode('utf-8')
         # Binary (1k bytes of data) decoded to utf-8 => unicode text string
        if fromClient == 'q':
            break
        print("From client:", addr)
        print("Received:", fromClient)

        mesg = input("Enter response: ")
        conn.send(mesg.encode('utf-8'))
        
        '''
        print('From client:', addr)
        x = 0
        x+= 1
            
        user = int(input('Number:'))
        conn.send(user) 
        conn.close()
        ''' 
    server.close()
    
if __name__ == '__main__':
    #highLevel()
    #print(ratio)
    lowLevel()
    
'''


'''
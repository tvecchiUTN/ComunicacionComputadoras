# Comunicacion entre computadoras

El presente repositorio son ejemplos de programas o aplicaciones de comunicacion entre computadoras, la comunicacion que se desea hacer el full-duplex, lo que significa que puedo escuchar y escribir a la vez.

 **Comunicacion Servidor-Usuario**

 Este progrtama esta hecho para que el servidor pueda comunicarse con un cliente. Como se puede ver es raro comunicarse con el servidor, uno en realidad se quiere comunicar con otro usuario, por eso es solo una demostracion de lo que se puede hacer. 
 Para ejecutarlo, del lado servidor solo necesito ejecutar la aplicacion *server.out*, este crea un hilo para escuchar al usuario y el principal para comunicarse con el usuario.
 Del lado cliente, solo basta con la aplicacion *telnet*, ingresar IP y puerto del servidor y listo. Aunque con esta aplicacion se vuelva mas sencillo, hay ciertos errores al recibir los datos, por ejemplo, si escribo algo y al mismo tiempo recibo algo, el texto recibido se sobrepondra al texto ingresado.

 **Comunicacion Usuario-Usuario**

 Lo esperado en este proyecto es conectarse con otro cliente y que el servidor se encarge de todo. El cliente solo envia y escucha, nada mas. Esto porque supuestamente el servidor es mas "rapido" o "fuerte" que otras computadoras y por este motivo se encarga de la parte pesada.
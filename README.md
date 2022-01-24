# STCP_AED
Our 2nd project for the AED classes
                                                                                                    
                 /############.                                                                     
             ,####################                                                                  
           /#####(            ######.                                                               
          #####                 .#####                                                              
      .*******.                  /#######            #######(  #########/   (########  #########    
    .***********.              (###########         ###(          ###/    .###.        ###,  (###   
    ****     ****              ####     ###(         *#######     ###/    ###(         #########    
    .*****.*****.              #####/,#####               ###,    ###/     ###(        ###,         
      ,********                  ########,          (#######      ###/       ########  ###,         
          *****.                ,****,                                                              
           .******            ******                                                                
              ********************                                                                  
                  ***********.                                                                      

### Requisitos mínimos:

    • Ler dados fornecidos no dataset.zip e criar um ou mais gafos (que serão alvos de operações)
    • Menu amigável que expõe as funcionalidades implementadas *done*
    • Calcular a distância mínima (a.k.a melhor percurso) entre duas localidades
    • Versões de local, melhor percurso e mudar de linha:
    • “Local” - tanto pode ser indicada diretamente uma paragem, como um localização (i.e., as coordenadas), onde pode ver as paragens que estejam perto dessa posição.
    • “Melhor” percurso - um utilizador pode querer o percurso que: passa por menos paragens; percorre menor distância; implica menos mudanças de autocarro (de linha); fica mais barato (passa por menos zonas), etc
    • “Mudar” de autocarro – para além de mudar de autocarro numa paragem, deve também ser possível caminhar um pouco para uma outra paragem “vizinha” (que esteja a menos do que uma certa distância).
    • Pelo menos uma BFS (grafos não pesados) e algoritmos de Dijskstra (caminhos curtos e grafos pesados)
    • Fórmula de Harversine (opcional) para calcular distâncias entre dois pontos (dadas a latitude e longitude)
    • Documentar em doxygen

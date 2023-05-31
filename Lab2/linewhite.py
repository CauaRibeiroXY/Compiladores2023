import os

arquivo = 'gram.txt'

if os.path.exists(arquivo):
    with open(arquivo, 'r') as f:
        conteudo = f.readlines()

    conteudo_sem_linhas_em_branco = [linha for linha in conteudo if linha.strip()]

    novo_arquivo = 'gramatica.conf'

    with open(novo_arquivo, 'w') as f:
        f.writelines(conteudo_sem_linhas_em_branco)
        f.write('\n') # Adiciona uma linha em branco no final do arquivo

    print(f"Arquivo '{arquivo}' lido com sucesso. O arquivo '{novo_arquivo}' foi criado sem linhas em branco.")
else:
    print(f"O arquivo {arquivo} não foi encontrado no diretório atual.")

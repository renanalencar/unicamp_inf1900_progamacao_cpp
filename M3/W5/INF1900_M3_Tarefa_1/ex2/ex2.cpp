/**
 * @file ex2.cpp
 *
 * @brief Classe com função main para execução dos pontos da atividade.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <locale> // Para configurar a codificação UTF-8

using namespace std;

struct Ferramenta {
	int numeroRegistro;
	wstring nomeFerramenta;
	int quantidade;
	double preco;
};

// Função para adicionar uma ferramenta ao arquivo
void adicionarFerramenta(const wstring& arquivoNome, const Ferramenta& ferramenta) {
	wofstream arquivo(arquivoNome, ios::app);
	arquivo.imbue(locale("pt_BR.utf8")); // Configura a codificação UTF-8

	if (!arquivo.is_open()) {
		cerr << L"Erro ao abrir o arquivo." << endl;
		exit(1);
	}

	arquivo << ferramenta.numeroRegistro << L';'
		<< ferramenta.nomeFerramenta << L';'
		<< ferramenta.quantidade << L';'
		<< ferramenta.preco << endl;

	arquivo.close();
}

// Função para listar todas as ferramentas do arquivo
void listarFerramentas(const wstring& arquivoNome) {
	wifstream arquivo(arquivoNome);
	arquivo.imbue(locale("pt_BR.utf8")); // Configura a codificação UTF-8

	if (!arquivo.is_open()) {
		cerr << L"Erro ao abrir o arquivo." << endl;
		exit(1);
	}

	Ferramenta ferramenta;
	vector<Ferramenta> ferramentas;
	wstring linha;

	while (getline(arquivo, linha)) {
		wstringstream ss(linha);
		wstring campo;

		getline(ss, campo, L';');
		ferramenta.numeroRegistro = stoi(campo);

		getline(ss, ferramenta.nomeFerramenta, L';');
		getline(ss, campo, L';');
		ferramenta.quantidade = stoi(campo);

		getline(ss, campo);
		ferramenta.preco = stod(campo);

		ferramentas.push_back(ferramenta);
	}

	arquivo.close();

	if (ferramentas.empty()) {
		wcout << L"Nenhuma ferramenta encontrada no inventário." << endl;
	}
	else {
		wcout << L"Lista de Ferramentas:" << endl;
		for (const Ferramenta& f : ferramentas) {
			wcout << L"Número de Registro: " << f.numeroRegistro << endl;
			wcout << L"Nome da Ferramenta: " << f.nomeFerramenta << endl;
			wcout << L"Quantidade: " << f.quantidade << endl;
			wcout << L"Preço: " << f.preco << endl << endl;
		}
	}
}

// Função para excluir uma ferramenta com base no número de registro
void excluirFerramenta(const wstring& arquivoNome, int numeroRegistro) {
	wifstream arquivoEntrada(arquivoNome);
	wofstream arquivoTemp(L"temp.dat");
	arquivoEntrada.imbue(locale("pt_BR.utf8")); // Configura a codificação UTF-8
	arquivoTemp.imbue(locale("pt_BR.utf8")); // Configura a codificação UTF-8

	if (!arquivoEntrada.is_open() || !arquivoTemp.is_open()) {
		cerr << L"Erro ao abrir o arquivo." << endl;
		exit(1);
	}

	Ferramenta ferramenta;
	bool encontrou = false;
	wstring linha;

	while (getline(arquivoEntrada, linha)) {
		wstringstream ss(linha);
		wstring campo;

		getline(ss, campo, L';');
		ferramenta.numeroRegistro = stoi(campo);

		getline(ss, ferramenta.nomeFerramenta, L';');
		getline(ss, campo, L';');
		ferramenta.quantidade = stoi(campo);

		getline(ss, campo);
		ferramenta.preco = stod(campo);

		if (ferramenta.numeroRegistro != numeroRegistro) {
			arquivoTemp << ferramenta.numeroRegistro << L';'
				<< ferramenta.nomeFerramenta << L';'
				<< ferramenta.quantidade << L';'
				<< ferramenta.preco << endl;
		}
		else {
			encontrou = true;
		}
	}

	arquivoEntrada.close();
	arquivoTemp.close();

	if (!encontrou) {
		wcout << L"Ferramenta com o número de registro " << numeroRegistro << L" não encontrada." << endl;
	}
	else {
		_wremove(arquivoNome.c_str());
		_wrename(L"temp.dat", arquivoNome.c_str());
		wcout << L"Ferramenta excluída com sucesso." << endl;
	}
}

int main() {
	wstring arquivoNome = L"hardware.dat";

	while (true) {
		// Configurar a localização temporária para aceitar números com vírgula
		locale loc("");
		wcout.imbue(loc);
		wcout << L"Escolha uma opção:" << endl;
		wcout << L"1. Adicionar uma ferramenta" << endl;
		wcout << L"2. Listar todas as ferramentas" << endl;
		wcout << L"3. Excluir uma ferramenta" << endl;
		wcout << L"4. Sair" << endl;

		int escolha;
		wcin >> escolha;

		if (escolha == 1) {
			Ferramenta novaFerramenta;
			wcout << L"Número de Registro: ";
			wcin >> novaFerramenta.numeroRegistro;
			wcin.ignore();
			wcout << L"Nome da Ferramenta: ";
			getline(wcin, novaFerramenta.nomeFerramenta);
			wcout << L"Quantidade: ";
			wcin >> novaFerramenta.quantidade;
			wcout << L"Preço: ";
			wcin.imbue(loc);
			wcin >> novaFerramenta.preco;

			adicionarFerramenta(arquivoNome, novaFerramenta);
			wcout << L"Ferramenta adicionada com sucesso." << endl;
		}
		else if (escolha == 2) {
			listarFerramentas(arquivoNome);
		}
		else if (escolha == 3) {
			int numeroRegistro;
			wcout << L"Informe o número de registro da ferramenta a ser excluída: ";
			wcin >> numeroRegistro;

			excluirFerramenta(arquivoNome, numeroRegistro);
		}
		else if (escolha == 4) {
			break;
		}
		else {
			wcout << L"Opção inválida. Tente novamente." << endl;
		}
	}

	return 0;
}
package br.gov.sp.fatec.quantogastarestfull.model;

import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;

/**
 * Classe que representa {@link Usuario}
 *
 */
@Getter
@Setter
public class Usuario {

	private Long id;
	private String nome;
	private List<ConsumoMensal> consumoMensalLista = new ArrayList<ConsumoMensal>();
	private List<Eletrodomestico> eletrodomesticos = new ArrayList<Eletrodomestico>();

	/**
	 * Método responsável por adicionar um {@link Eletrodomestico} à lista
	 * @param eletrodomestico	Objeto {@link Eletrodomestico}
	 */
	public void resgistrarEletrodomestico(final Eletrodomestico eletrodomestico) {
		eletrodomesticos.add(eletrodomestico);
	}

	/**
	 * Método responsável por adicionar o consumo mensal de um {@link Eletrodomestico} à lista
	 * @param consumoMensal		Objeto {@link ConsumoMensal}
	 */
	public void registrarConsumoMensal(final ConsumoMensal consumoMensal) {
		consumoMensalLista.add(consumoMensal);
	}

	/**
	 * Método responsável por consultar consumo mensal
	 * @param mesAno	mes/ano para consulta
	 * @return			Objeto {@link ConsumoMensal}
	 */
	public ConsumoMensal pesquisarConsumoMensal(final String mesAno) {
		for (final ConsumoMensal consumoMensal : consumoMensalLista) {
			if (consumoMensal.getMesAno().equals(mesAno))
				return consumoMensal;
		}
		return null;
	}

	/**
	 * Método responsável por pesquisar {@link Eletrodomestico}
	 * @param nome	do Eletrodoméstico
	 * @return		Lista de {@link Eletrodomestico}
	 */
	public List<Eletrodomestico> pesquisarEletrodomestico(final String nome) {
		List<Eletrodomestico> eletrodomesticos = new ArrayList<>();
		for (final Eletrodomestico eletrodomestico : this.eletrodomesticos) {
			if (eletrodomestico.getNome().equals(nome)) {
				eletrodomesticos.add(eletrodomestico);
			}
			return eletrodomesticos;
		}
		return eletrodomesticos;
	}
}

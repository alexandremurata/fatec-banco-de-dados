package br.gov.sp.fatec.quantogastarestfull.model;

import lombok.Getter;
import lombok.Setter;

/**
 * Classe que representa {@link Eletrodomestico}
 */
@Getter
@Setter
public class Eletrodomestico {

	private Long id;
	private String nome;
	private Float potencia;
	private Float qtdeHoras;
	private Float consumoPorHora;
	private Usuario usuario;

	/**
	 * Construtor
	 */
	public Eletrodomestico() {
		super();
	}

	/**
	 * Construtor com parâmetros
	 * @param nome			do Eletrodoméstico
	 * @param potencia		do Eletrodoméstico
	 * @param qtdeHoras		do Eletrodoméstico
	 */
	public Eletrodomestico(String nome, Float potencia, Float qtdeHoras) {
		this.nome = nome;
		this.potencia = potencia;
		this.qtdeHoras = qtdeHoras;
	}

	/**
	 * Método responsável por calcular o consumo por hora do eletrodoméstico
	 * @param qtdHoraMes
	 * @param potencia		do eletrodoméstico
	 * @return				consumo por hora
	 */
	public Float calcularConsumoPorHora(final Float qtdHoraMes, final Float potencia){
		return qtdHoraMes * potencia;
	}

}

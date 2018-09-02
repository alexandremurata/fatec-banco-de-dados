package br.gov.sp.fatec.quantogastarestfull.model;

import br.gov.sp.fatec.quantogastarestfull.utils.ConstantsUtils;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;

@Getter
@Setter
public class ConsumoMensal {
	private Long id;
	private String mesAno;
	private Float valor;
	private Float totalKWH;
	private String bandeira;
	private Tarifa tarifa;
	private Usuario usuario;
	private List<Float> consumosPorHora = new ArrayList<>();

	public ConsumoMensal(){
		super();
	}

	public ConsumoMensal(String mesAno, Float valor) {
		this.mesAno = mesAno;
		this.valor = valor;
	}

	public Float calcularConsumoMensal(final Tarifa tarifa, final Float totalKWH, final String bandeira) {

		if (ConstantsUtils.VERMELHO.equalsIgnoreCase(bandeira)) {
			return totalKWH * tarifa.getValor() + (totalKWH / 100) * 3;
		}
		if (ConstantsUtils.AMARELO.equalsIgnoreCase(bandeira)) {
			return totalKWH * tarifa.getValor() + (totalKWH / 100) * 2;
		}

		return totalKWH * tarifa.getValor();
	}

	public void registarConsumoPorHora(final Float consumoPorHora) {
		if(consumoPorHora != null) {
			consumosPorHora.add(consumoPorHora);
		}
	}

}
